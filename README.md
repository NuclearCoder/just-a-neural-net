# Just a Neural Network
Experimental neural network written from scratch in C++
 
Development is done live on Sundays [on Twitch](https://www.twitch.tv/nuclearcoder).  
First stream: 2 oct. 2016, 15h28  
End of last stream: 2 oct. 2016, 19h48  

Last stream sticky note content:
```
* fix those horrible exception messages
* TODO: replace vector<Matrix> argument with vector<uint_t> with only the sizes, since the weights are randomly generated anyway
* cross-entropy loss function
* TODO: normalize input
* TODO: remove calls in for looop conditions
```

Done so far (from top to bottom, in chronological order):
* matrices and basic operations
* multi-layer network with fixed topology (fixed at initialisation)
* random weights on init (normal distribution)
* basic forward propagation

