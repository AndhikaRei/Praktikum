/* Bagian <1> */
/* Deklarasi Fakta */ 
/* Deklarasi Fakta 1.1.a*/
pria(yoga).
pria(zaynMalik).
pria(padil).
pria(jovan).
pria(zunan).
pria(farras).
pria(william).
pria(smallFaris).
pria(babyThajep).

/* Deklarasi Fakta 1.1.b*/
wanita(lisa).
wanita(asin).
wanita(rikha).
wanita(siti).
wanita(nurbaya).

/* Deklarasi Fakta 1.1.c*/
usia(yoga,71).
usia(lisa,65).
usia(zaynMalik,56).
usia(asin,51).
usia(padil,58).
usia(rikha,40).
usia(jovan,24).
usia(zunan,30).
usia(farras,32).
usia(siti,26).
usia(william,28).
usia(nurbaya,24).
usia(smallFaris,6).
usia(babyThajep,3).

/* Deklarasi Fakta 1.1.d*/
menikah(yoga,lisa).
menikah(lisa,yoga).
menikah(zaynMalik,asin).
menikah(asin,zaynMalik).
menikah(padil,rikha).
menikah(rikha,padil).
menikah(farras,siti).
menikah(siti,farras).
menikah(william,nurbaya).
menikah(nurbaya,william).

/* Deklarasi Fakta 1.1.e*/
anak(jovan,yoga).
anak(jovan,lisa).
anak(zunan,yoga).
anak(zunan,lisa).
anak(farras,yoga).
anak(farras,lisa).
anak(siti,zaynMalik).
anak(siti,asin).
anak(william,zaynMalik).
anak(william,asin).
anak(nurbaya,padil).
anak(nurbaya,rikha).
anak(smallFaris,farras).
anak(smallFaris,siti).
anak(babyThajep,william).
anak(babyThajep,nurbaya).

/* Deklarasi Fakta 1.1.f*/
saudara(jovan,zunan).
saudara(zunan,jovan).
saudara(jovan,farras).
saudara(farras,jovan).
saudara(zunan,farras).
saudara(farras,zunan).
saudara(siti,william).
saudara(william,siti).

/* Deklarasi Rules */
/* Deklarasi Rules 1.2.a */
kakak(X,Y) :-
	saudara(X,Y),
	usia(X,UX),
	usia(Y,UY),
	UX >= UY.

/* Deklarasi Rules 1.2.b */
keponakan(X,Y) :-
	\+anak(X,Y),
	anak(X,Z),
	saudara(Z,Y).
keponakan(X,Y) :-
	\+anak(X,Y),
	keponakan(X,Z),
	menikah(Z,Y).

/* Deklarasi Rules 1.2.c */
suami(X,Y) :-
	pria(X),
	menikah(X,Y),
	wanita(Y).

/* Deklarasi Rules 1.2.d */
sepupu(X,Y) :-
	\+saudara(X,Y),
	anak(X,PX),
	anak(Y,PY),
	saudara(PX,PY).

/* Deklarasi Rules 1.2.e */
mertua(X,Y) :-
	\+anak(Y,X),
	menikah(Y,Z),
	anak(Z,X).

/* Deklarasi Rules 1.2.f */
bibi(X,Y) :-
	\+anak(Y,X),
	anak(Y,Z),
	saudara(Z,X),
	wanita(X).

/* Deklarasi Rules 1.2.g */
cucu(X,Y) :-
	anak(X,Z),
	anak(Z,Y).

/* Deklarasi Rules 1.2.h */
anakSulung(X) :-
	\+saudara(X,_),
	anak(X,_).
anakSulung(X) :-
	\+kakak(_,X),
	anak(X,_).

/* Deklarasi Rules 1.2.i */
anakBungsu(X) :-
	\+saudara(X,_),
	anak(X,_).
anakBungsu(X) :-
	\+kakak(X,_),
	anak(X,_).

/* Bagian <2> */ 
/* Deklarasi Fakta 2.1*/
/* Deklarasi Rules 2.1*/
faktorial(0,X) :- X is 1.
faktorial(Y,X) :- 
	Y > 0,
	Z is Y-1,
	faktorial(Z,X2),
	X is Y*X2.
 
/* Deklarasi Fakta 2.2*/
/* Deklarasi Rules 2.2*/
gcd(A,0,X) :- 
	A > 0,
	X is A.
gcd(A,B,X) :- 
	A > 0,
	B > 0, 
	A1 is B,
	B1 is A mod B,
	gcd(A1,B1,X).

/* Deklarasi Fakta 2.3*/
power(0,0,X):-
	X = 'No',!.
power(_,0,X) :- X is 1.
/* Deklarasi Rules 2.3*/
power(A,B,X) :-
	B > 0,
	B1 is B-1,
	power(A,B1,X1),
	X is X1*A.
power(A,B,X) :-
	B < 0,
	B1 is B+1,
	power(A,B1,X1),
	X is X1/A.

/* Deklarasi Fakta 2.4*/
/* Deklarasi Rules 2.4*/
countDigit(A,X) :- 
	A < 10,
	A > -10, 
	X is 1,!.
countDigit(A,X) :-
	A1 is A//10,
	countDigit(A1,X1),
	X is 1 + X1.

/* Deklarasi Fakta 2.5*/
/* Deklarasi Rules 2.5*/
printBintang(X) :- 
	X =:= 1,
	write('x'), nl.
printBintang(X) :- 
	X > 0,
	write('x'),
	X1 is X-1,
	printBintang(X1).
createTriangle(0).
createTriangle(X):-
	X >= 0,
	printBintang(X),
	X1 is X-1,
	createTriangle(X1),!.


/* Bagian <3> */ 

/* Deklarasi Fakta 3.1*/
push(A,[],[A]).
/* Deklarasi Rules 3.1*/
push(El,[H|T1],[H|T2]) :- 
	push(El,T1,T2).

/* Deklarasi Fakta 3.2*/
pop([],[]).
/* Deklarasi Rules 3.2*/
pop([_|T],T).

/* Deklarasi Fakta 3.3*/
/* Deklarasi Rules 3.3*/
front([H|_],H).

/* Deklarasi Fakta 3.4 */
back([A],A).
/* Deklarasi Rules 3.4 */
back([_|T],X):-
	back(T,X).

/* Deklarasi Fakta 3.5*/
concatenate([_|_],[_|_],0,0,[]).
concatenate([],[_|_],0,0,[]).
concatenate([_|_],[],0,0,[]).
concatenate([],[],0,0,[]).
/* Deklarasi Rules 3.5*/
concatenate([H|T],[H3|T3],X,Y,[H|T2]) :-
	X > 0,
	X1 is X-1,
	concatenate(T,[H3|T3],X1,Y,T2).
concatenate([_|_],[H|T1],0,Y,[H|T2]):-
	Y > 0,
	Y1 is Y-1,
	concatenate([_|_],T1,0,Y1,T2).
concatenate([],[H|T1],0,Y,[H|T2]):-
	Y > 0,
	Y1 is Y-1,
	concatenate([],T1,0,Y1,T2).

/* Deklarasi Fakta 3.6*/
pop2([_],[]).
pop2([],[]).
pop2([H|T1],[H|T2]):-
	pop2(T1,T2).
/* Deklarasi Rules 3.6*/
/* reverse tidak kepakai karena hanya coba coba */
startReverse(L,X) :-
	reverse2(L,[],X).
reverse2([],X,X).
reverse2([H|T],T2,X):-
	reverse2(T,[H|T2],X).
palindrom([]).
palindrom(L):-
	front(L,F),
	back(L,B),
	F =:= B,
	pop(L,L2),
	pop2(L2,L3),!,
	palindrom(L3).

/* Bagian <4> */ 
/* Deklarasi Fakta */
ridge2([_,_],0).
ridge2([_],0).
ridge2([],0).
/* Deklarasi Rules */
ridge2([H1,H2,H3|T],X):-
	H1 > H2,
	H3 > H2,
	ridge2([H3|T],X1),
	X is 1 + X1.
ridge2([H1,H2,H3|T],X):-
	\+ H1 > H2,
	\+ H3 > H2,
	ridge2([H2,H3|T],X1),
	X is 0 + X1.
ridge2([H1,H2,H3|T],X):-
	\+ H1 > H2,
	H3 > H2,
	ridge2([H2,H3|T],X1),
	X is 0 + X1.
ridge2([H1,H2,H3|T],X):-
	H1 > H2,
	\+ H3 > H2,
	ridge2([H2,H3|T],X1),
	X is 0 + X1.
ridge([H1,H2,H3|T]):-
	ridge2([H1,H2,H3|T],X),!,
	X =\= 0,
	write(X).
