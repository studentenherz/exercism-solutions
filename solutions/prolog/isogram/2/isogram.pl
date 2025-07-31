isogram_helper([_]).
isogram_helper([X, Y]) :- dif(X, Y).
isogram_helper([X, Y | L]) :-
	dif(X, Y),
	isogram_helper([Y | L]).

isogram("").
isogram(L) :-
	string_to_atom(L, AtomStr),
	downcase_atom(AtomStr, LowerCase),
	atom_chars(LowerCase, StrChars),
	include([C]>>char_type(C, alpha), StrChars, OnlyAlpha),
	msort(OnlyAlpha, SortedArr),
	isogram_helper(SortedArr).