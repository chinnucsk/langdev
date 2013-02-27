;; mexprs

subst[x;y;z]
subst[x;y;cdr[z]]

diff [y; x] = [atom[y] -> [eq[y; x] -> ONE; 
                           T        -> ZERO]; 
               eq[car [Y]; PLUS]  -> cons[PLUS; 
                                          maplist[cdr[y]; λ[[z]; diff[car [z]; x]]]]; 
               eq[car [y]; TIMES] -> cons[PLUS; maplist[cdr[y]; 
                                                        λ[[z]; 
                                                          cons[TIMES; 
                                                               maplist[cdr [y]; 
                                                                       λ[[w]; 
                                                                         ¬eq [z; w] -> car [w]; 
                                                                         T          -> diff[car[[w]; x]]]]]]]]]
