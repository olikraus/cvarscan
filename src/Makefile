LEX	= flex -Cr
YACC	= bison --debug --locations
YFLAGS	= 
CFLAGS	= -g -Wall
LFLAGS	=
LDFLAGS = -lm -g 

OBJ=c_gram.tab.o c_scan.o c_const.o main.o c_ast.o c_ast_c.o c_ast_path.o\
	c_el.o c_ell.o c_fi.o c_util.o c_fi_decl.o c_fi_file.o c_eval.o\
	c_fi_type.o c_fi_fn.c c_fi_va.o c_mtql.o\
	c_fi_id.o c_init.o\
	b_pl.o b_il.o b_io.o b_ds.o
	
	
cvarscan: $(OBJ) c_gram.output
	${CC} ${CFLAGS} -o $@ $(OBJ) ${LDFLAGS}


c_tok.h: c_gram.y
	$(YACC) --defines=$@ --output-file=/dev/null c_gram.y
        
c_gram.output: c_gram.y
	$(YACC) -v c_gram.y

bison_extract: bison_extract.c
	${CC} ${CFLAGS} -o $@ bison_extract.c ${LDFLAGS}

c_const.c: c_gram.output bison_extract
	-./bison_extract c c_gram.output > c_const.c

c_const.h: c_gram.output bison_extract
	-./bison_extract h c_gram.output > c_const.h

c_scan.c: c_scan.l c_tok.h

c_gram.tab.c: c_gram.y
	$(YACC) c_gram.y

c_ast.c: c_ast.h c_const.h


clean:
	-rm c_gram.tab.c c_tok.h c_scan.c *.o cvarscan y.output\
        bison_extract c_gram.output c_const.c

zip:
	zip cvarscan_`date +%F_%H-%M`.zip *.c *.h *.y *.l Makefile info.txt *.output
	cp *.zip /media/CANON_DC/.
	