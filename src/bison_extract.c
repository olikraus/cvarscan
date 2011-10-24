/*

  bison_extract.c

  extract constant strings from a bison output file
  there are two options: c-file and header file generation

  bison_extract 'h'|'c' <bison_output_file>

*/

#include <stdio.h>
#include <string.h>

FILE *fp;
char buf[1024];
int max_str_len = 0;
int total_cnt = 0;
char *prefix = "c_";

int read_buf()
{
  if ( fgets(buf, 1024, fp) == NULL )
    return 0;
  return 1;
}

int find_string(const char *s1, const char *s2)
{
  size_t l1 = strlen(s1);
  size_t l2 = strlen(s2);
  for(;;)
  {
    if ( read_buf() == 0 )
      return 0;
    if ( strncmp(buf, s1, l1) == 0 )
      return 1;
    if ( strncmp(buf, s2, l2) == 0 )
      return 1;
  }
}

void normalize_str(char *s)
{
  for(;;)
  {
      if ( *s == '\0' )
	break;
      if ( *s == '-' )
	*s = '_';
      s++;
  }
}

int next_valid_line()
{
    for(;;)
    {
      if ( (buf[0] >= 'a' && buf[0] <= 'z') || (buf[0] >= 'A' && buf[0] <= 'Z') || buf[0]=='_' )
        return 1;
      if ( read_buf() == 0 )
        return 0;
    }
}

char *get_first_string()
{
  return strtok(buf, " \t");
}


/*
  phase 0: init
  phase 1: table
  phase 2: c-refs

  phase 100: h-file
*/

int gen_nonterminals(int phase)
{
  char *s;
  int cnt = 0;
  
  fseek(fp, 0L, SEEK_SET);
  if ( find_string("Nonterminals", "Nicht-Terminal") == 0 )
    return 0;
  if ( phase == 0 )
  {
    total_cnt = 0;
  }
  else if ( phase == 1 )
  {
    printf(
      "const char %sconstant_str_table[%d][%d] = {\n", 
      prefix, total_cnt, max_str_len+1);
  }
  else if ( phase == 100 )
  {
    printf(
      "extern const char %sconstant_str_table[%d][%d] ;\n", 
      prefix, total_cnt, max_str_len+1);
  }
  
  for(;;)
  {
    if ( next_valid_line() == 0 )
      return 1;
    s = get_first_string();
    if ( s == NULL )
      return 0;
    if ( strcmp(s, "state") == 0 )
      break;
    if ( strcmp(s, "Zustand") == 0 )
      break;
    
    normalize_str(s);
    
    if ( phase == 0 )
    {
      if ( max_str_len < strlen(s) )
        max_str_len = strlen(s);
      total_cnt++;
    }
    else if ( phase == 1 )
    {
      cnt++;
      printf("\"%s\"%s\n", s, cnt==total_cnt?"":",");
    }
    else if ( phase == 2 )
    {
      printf("const char *%sstr_%s = %sconstant_str_table[%d];\n",
        prefix, s, prefix, cnt);
      cnt++;
    }
    else if ( phase == 100 )
    {
      printf("extern const char *%sstr_%s;\n", prefix, s);
      cnt++;
    }
    else if ( phase == 101 )
    {
      printf("#define %sdef_%s (%sconstant_str_table[%d]) \n", prefix, s, prefix, cnt);
      cnt++;
    }
    if ( read_buf() == 0 )
      break;
  }
  if ( phase == 1 )
    printf("};\n");
  return 1;
}

int main(int argc, char **argv)
{
  char *cmd;
  if ( argc <= 2 )
  {
    printf("%s {c|h} bison.output [prefix]\n", argv[0]);
    return 1;
  }
  
  cmd = argv[1];
  
  fp = fopen(argv[2], "r");
  if ( fp == NULL )
    return 1;
  
  if ( argc == 4 )
  {
    prefix = argv[3];
  }

  if ( *cmd == 'c' )
  {
    gen_nonterminals(0);
    gen_nonterminals(1);
    gen_nonterminals(2);
  }
  if ( *cmd == 'h' )
  {
    gen_nonterminals(0);
    gen_nonterminals(100);
    gen_nonterminals(101);
  }
  
  
  return 0;
}


