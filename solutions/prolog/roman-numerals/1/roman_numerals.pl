convert(0, "").
convert(1, "I").
convert(4, "IV").
convert(5, "V").
convert(9, "IX").
convert(10, "X").
convert(40, "XL").
convert(50, "L").
convert(90, "XC").
convert(100, "C").
convert(400, "CD").
convert(500, "D").
convert(900, "CM").
convert(1000, "M").

convert(N, Roman) :- N < 9,
	N1 is N - 1,
	convert(N1, FirstPart),
	string_concat(FirstPart, "I", Roman).

convert(N, Roman) :- N < 100, N mod 10 =:= 0,
	N1 is N - 10,
	convert(N1, FirstPart),
	string_concat(FirstPart, "X", Roman).

convert(N, Roman) :- N < 100,
	Rest is N mod 10,
	N1 is N - Rest,
	convert(N1, FirstPart),
	convert(Rest, SecondPart),
	string_concat(FirstPart, SecondPart, Roman).

convert(N, Roman) :- N < 1000, N mod 100 =:= 0,
	N1 is N - 100,
	convert(N1, FirstPart),
	string_concat(FirstPart, "C", Roman).

convert(N, Roman) :- N < 1000,
	Rest is N mod 100,
	N1 is N - Rest,
	convert(N1, FirstPart),
	convert(Rest, SecondPart),
	string_concat(FirstPart, SecondPart, Roman).

convert(N, Roman) :- N > 1000,
	N1 is N - 1000,
	convert(N1, SecondPart),
	string_concat("M", SecondPart, Roman).