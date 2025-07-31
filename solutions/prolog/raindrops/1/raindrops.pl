convert(N, Result) :-
    (N mod 3 =:= 0 -> T1 = "Pling"; T1 = ""),
    (N mod 5 =:= 0 -> T2 = "Plang"; T2 = ""),
    (N mod 7 =:= 0 -> T3 = "Plong"; T3 = ""),
    (T1 = "" , T2 = "" , T3 = "" -> number_string(N, Result) ; 
        string_concat(T1, T2, PartResult),
        string_concat(PartResult, T3, Result) 
    ).
