:- use_module(library(pita)).
:- pita.

:- begin_lpad.
heads(Coin): 1/2; tails(Coin) : 1/2:-toss(Coin),\+biased(Coin).
heads(Coin): 0.6 ; tails(Coin) : 0.4:-toss(Coin),biased(Coin).
fair(Coin):0.9 ; biased(Coin):0.1.
toss(coin).
:- end_lpad.

pheads(P) :- prob(heads(coin), P).
ptails(P) :- prob(tails(coin), P).
