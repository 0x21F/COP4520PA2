# Program 2 

## Problem 1 
General Idea is this 

let n equal the number of partygoers
- first partygoer eats the cupcake
- the rest of the partygoers request cupcakes if they haven't entered before,  , 
otherwise they leave the stand as it was when they entered. 
- First partygoer is counting their calories in units of cupcakes. Once they hit n cupcakes then they know all participants. 

The only time a cupcake should be there is if someone hasn't entered before, if the entrants have entered they leave it as is so the first can count. 


## problem 2 
Test and Test and set with some extra stuff added so people don't go in multiple times. 
It would be the 2nd approach with an added backoff period so the people can experience the party a little bit. It's also fair too so no partygoer can complain.

This is arguably more ideal than the 3rd queue system since I'm restricting the max N threads to like 16. Anderson queues would likely be slower at such numbers (if we follow the slides).

# Running this stuff
I'll probably make a MakeFile in the morning but for now cope.
