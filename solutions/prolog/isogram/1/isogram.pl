isogram_helper([_]).
isogram_helper([X, Y]) :- (dif(X, Y); member(X, [' ', '-'])).
isogram_helper([X, Y | L]) :-
	(dif(X, Y); member(X, [' ', '-'])),
	isogram_helper([Y | L]).

isogram("").
isogram(L) :-
	string_to_atom(L, AtomStr),
	downcase_atom(AtomStr, LowerCase),
	atom_chars(LowerCase, StrChars),
	msort(StrChars, SortedArr),
	isogram_helper(SortedArr).