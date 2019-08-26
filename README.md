# Sir Forkalot
*How expensive is `fork()`, really?*

This project benchmarks `fork()` under optimal conditions so we can cast some
suspicion on the narrative that forking is always expensive. Just run `make`,
and you'll see how long it takes (real time) to spawn (and reap) 10,000 children
on a single cpu of your workstation.
