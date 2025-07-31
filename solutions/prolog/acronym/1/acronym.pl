acronym([], Sofar, Acc) :- Acc = Sofar.
acronym([' ', A | L], Sofar, Acc) :-
	char_type(A, alpha),
	upcase_atom(A, UpperCase),
	append(Sofar, [UpperCase], NewSofar),
	acronym(L, NewSofar, Acc).
acronym([_ | L], Sofar, Acc) :-
	acronym(L, Sofar, Acc).

abbreviate(Sentence, Acronym) :-
	re_replace("-", " ", Sentence, NewSentence1),
	string_chars(NewSentence1, CharArr),
	exclude([C]>>char_type(C, punct), CharArr, NewSentence),
	append([' '], NewSentence, WhitespaceCharArr),
	acronym(WhitespaceCharArr, [], AcronymArr),
	atom_string(AcronymArr, Acronym).