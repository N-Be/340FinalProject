CSCI 340 FALL 2020
Taught by Dr. Anthony Leclerc

Project by: Nathan Bell and Hollande Powell




This program is meant to be able to find through experimentation
	1) how big is a cache block?
	2) how big is the cache?
	3) how long does a reference to main memory take to complete?
	4) how long does a reference that can be satisfied from cache take to complete?
	
	
This README file will go through our findings for each of these questions.

So from the start it seems like this is a project that wont ever be able to find any straight answers.

If we were to be able to get any definitive answer there would be no need for "experimentation" as mentioned in the assignment pdf.

With prefetching it is hard to ensure where data is being pulled from.

And the cpu never being solely used for the program we are running any timing we do will have unpredictable variability.

Keep in mind that every position that is referenced in this readme is referencing that of an integer array where 1 index is 4bytes.  


--------------------------------------------------------------------------------------------------------
How big is a cache block?

	If you navigate below the main function in how the C file currently looks you will find a bunch of commented out other methods and one section from an old version of main that we were using to try to figure out the answers to the first two questions. No matter what we brainstormed, nothing seemed to give us any conclusive evidence of what either the cache block size or cache size was. We could see a somewhat consistent spike in time taken to reference values in an integer array around indexes 128, 16384, and 134217728 but it is unclear to us where the cache ends and the main memory begins. 
	
We do not have any current ideas that might get us closer to answering those questions. Only more questions that would need to be answered before we could attempt to make meaningful progress.

--------------------------------------------------------------------------------------------------------
How big is the cache?




--------------------------------------------------------------------------------------------------------
HOW LONG DOES A REFERENCE TO MAIN MEMORY TAKE TO COMPLETE?

	When trying to find out how long it takes to reference something in main memory we had to first try to ensure that what we were referencing had a good possibility to be in main memory.
	In trying to get that good possibility we decided to index by powers of two and start at position 512 in our random integer array. 
	We started a timer before the loop and ended it after then returned an average of the time passed.


	THIS CAME OUT TO AROUND 100 - 135 NANOSECONDS
	
	This likely is a bit longer or shorter than what the time taken actually is due to our inability to be 100% certain that what we are referencing is in main memory, as well as other external circumstances that we cannot control. 

-------------------------------------------------------------------------------------------------------
HOW LONG DOES A REFERENCE TO THAT CAN BE SATISFIED FROM CACHE TAKE TO COMPLETE?

	In order to try and figure out the answer to this question we came up with the method we call avgCacheTime.
	In that method we get the time in nanoseconds before and after a loop that indexes the first position in an array over and over again for the entire size of the array. 
	Then average the time passed out to find a number that should represent the amount of nanoseconds it takes on average for a reference to cache to be made. 
	
	
	THIS CAME OUT TO AROUND 2.8 - 3.0 NANOSECONDS
	
	
	This likely is a bit longer than what it actually takes but due to external circumstances and processing other lines like the for loop or the line that gets the end time. 
	
