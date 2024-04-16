#ifndef BIT_H
#define BIT_H
#endif
#define	SET(NUM,BIT) NUM|(1<<BIT)
#define	CLEAR(NUM,BIT) NUM&~(1<<BIT)
#define	TOGGLE(NUM,BIT) NUM^(1<<BIT)
#define	GET(NUM,BIT) (NUM>>BIT)&1