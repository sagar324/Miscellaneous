# Project_1
# Brief intro
A C++ code which creates the top 5 Dream-11 teams(on the basis of stats) for a cricket match.<br/>

# Requirements:
Knowledge about Dream11, C++

# Purpose of this project:
As we know, there are many dream11 teams possible for a given match.<br/>
Using combinatorics and simple constraints,we can calculate the max number of teams possible is 644688.<br/>
644688 is comparably a small number for computational analysis.<br/>
So we give the playing 22 as input and extract the best 5 teams possible by considering all possible constraints.<br/>

# Overview:
I built a database/csv file(STATS.csv) using previous IPL stats from iplt20.com,<br/>
In the case of a player who didn't play previous IPL I manually checked the profile and added an approxiamate analysis based entry to the database.<br/>
The csv file consists of 5 columns:<br/>
Column1 - Name of player<br/>
Column3 - Number of matches played recently <br/>
Column2 - Avg points in those matches<br/>
Column4 - Cost of player in Dream11.<br/>
Column5 - Role of the player(0 for wk,1 for batsman,2 for all-rounder,3 for bowler)<br/>

# How to use the code?
There are 2 aspects to the code that I wrote:<br/>
1. Create best 5 teams by giving playing 22.<br/>
2. Updating database after the match.<br/>

So I will brief about Point-1 first:<br/>
# How to use the code for generating best 5 teams?
I have taken standard input from INPUT.txt and standard output to OUTPUT.txt ,in sublime text,(If you don't want to use sublime then comment the stext function call in line 398 of the code)<br/>
Write "create" in the first line of the input file (INPUT.txt in my case)<br/>
Then in the next 22 lines write name of each player(without spaces)<br/>
(NOTE::The first 11 lines should contain playing 11 of 1 team and the next 11 players should be of the other team.) <br/>
<br/>
Case-(1):In case the code doesn't find a player mentioned in the input file,<br/>
The code doesn't execute and gives the names of players who weren't found.<br/>
Case-(2):The code finds all players in the csv file and executes and prints the best 5 teams to OUTPUT.txt<br/>

SampleInput_1:<br/>
----------------------
create<br/>
DavidWarner<br/>
JonnyBairstow<br/>
ManishPandey<br/>
PriyamGarg<br/>
VijayShankar<br/>
MitchellMarsh<br/>
AbhishekSharma<br/>
RashidKhan<br/>
BhuvneshwarKumar<br/>
SandeepSharma<br/>
Natarajan<br/>
AaronFinch<br/>
ViratKohli<br/>
AbdeVilliers<br/>
DevduttPadikkal<br/>
ShivamDube<br/>
WashingtonSundar<br/>
UmeshYadav<br/>
DaleSteyn<br/>
NavdeepSaini<br/>
YuzvendraChahal<br/>
JoshPhillipe<br/>

SampleOutput_1: </br>
--------------------------------------------

The best 5 teams are::</br>
</br>
Estimated points for team-1 = 566.82</br>
DavidWarner(C) </br>
JonnyBairstow </br>
ManishPandey </br>
RashidKhan </br>
AaronFinch </br>
AbdeVilliers </br>
DevduttPadikkal(VC)</br> 
ShivamDube </br>
DaleSteyn </br>
YuzvendraChahal</br> 
JoshPhillipe </br>
-------------------------------------</br>
Estimated points for team-2 = 566.22</br>
DavidWarner(C) </br>
JonnyBairstow </br>
ManishPandey </br>
RashidKhan </br>
AaronFinch </br>
AbdeVilliers </br>
DevduttPadikkal(VC)</br> 
WashingtonSundar </br>
DaleSteyn </br>
YuzvendraChahal</br> 
JoshPhillipe </br>
-------------------------------------</br>
Estimated points for team-3 = 565.607</br>
DavidWarner(C) </br>
JonnyBairstow </br>
ManishPandey </br>
SandeepSharma </br>
AaronFinch </br>
ViratKohli </br>
AbdeVilliers </br>
DevduttPadikkal(VC)</br> 
ShivamDube </br>
DaleSteyn </br>
YuzvendraChahal</br> 
-------------------------------------</br>
Estimated points for team-4 = 565.007</br>
DavidWarner(C) </br>
JonnyBairstow </br>
ManishPandey </br>
SandeepSharma </br>
AaronFinch </br>
ViratKohli </br>
AbdeVilliers </br>
DevduttPadikkal(VC)</br> 
WashingtonSundar </br>
DaleSteyn </br>
YuzvendraChahal</br> 
-------------------------------------</br>
Estimated points for team-5 = 563.229</br>
DavidWarner(C) </br>
JonnyBairstow </br>
ManishPandey </br>
PriyamGarg </br>
RashidKhan </br>
AaronFinch </br>
AbdeVilliers </br>
DevduttPadikkal(VC)</br> 
ShivamDube </br>
DaleSteyn </br>
YuzvendraChahal</br> 
-------------------------------------</br>

SampleInput_2 :<br/>
----------------------
create<br/>
DavidWarner<br/>
JonnyBairstow<br/>
ManishPandey<br/>
PriyamGarg<br/>
VijayShankar<br/>
MitchellMarsh<br/>
AbhishekSharma<br/>
RashidKhan<br/>
BhuvneshwarKumar<br/>
SandeepSma<br/>
Natarajan<br/>
AaronFinch<br/>
Viratohli<br/>
AbdeVillier<br/>
DevduttPadikkal<br/>
ShivamDube<br/>
WashingtonSundar<br/>
UmeshYadav<br/>
DaleSteyn<br/>
NavdeepSaini<br/>
YuzvendraChahal<br/>
JoshPhillipe<br/>

SampleOutput_2 : <br/>
-----------------------
The following player/players were not found in the csv:<br/>
SandeepSma<br/>
Viratohli<br/>
AbdeVillier<br/>

Note that now I have deliberately introduced some typos in the sample input.<br/>
But the code finds them out.Even in the next part(database update) the code first checks whether all players mentioned are in the csv or not and gives an error like this(SampleOutput-2) if any player is not available in the csv.<br/>
# How to update the database after the match?
I have taken standard input from INPUT.txt and standard output to OUTPUT.txt ,in sublime text,(If you don't want to use sublime then comment the stext function call in line 398 of the code)<br/>
Write "update" in the first line of INPUT.txt,which is followed by 22 lines containing each player and number of points earned by him in that match.<br/>
<br/>
Case-(1): Due to typo,the player might not be found in the csv file. <br/>
In that case the code doesn't execute at all and just reports all the players who weren't found in the csv file.<br/>
Case-(2): The code finds that all 22 players are available in the csv file,<br/>
So it updates "avg points" aka Column 2 and "number of innings" aka Column 3 for each player.<br/>

SampleInput(Based on match on 21 sept 2020)for updating database:<br/>
-----------------------------------------------------------------------
update<br/>
DavidWarner 11<br/>
JonnyBairstow 101<br/>
ManishPandey 49<br/>
PriyamGarg 17<br/>
VijayShankar 27<br/>
MitchellMarsh 2<br/>
AbhishekSharma 37<br/>
RashidKhan 19<br/>
BhuvneshwarKumar 4<br/>
SandeepSharma 12<br/>
Natarajan 32<br/>
AaronFinch 38<br/>
ViratKohli 34<br/>
AbdeVilliers 71<br/>
DevduttPadikkal 76 <br/>
ShivamDube 63 <br/>
WashingtonSundar 4 <br/>
UmeshYadav 16<br/>
DaleSteyn 27<br/>
NavdeepSaini 62<br/>
YuzvendraChahal 83 <br/>
JoshPhillipe 11<br/>

SampleOutput:<br/>
------------------
Update Complete <br/>

# Few points to note :

Make sure that D11CODE.cpp,INPUT.txt,OUTPUT.txt,STATS.csv remain in the same folder.<br/>

Advantages of this project:
---------------------------
1. You don't need to waste your time thinking of all combinations(one may think of 50 combinations at max) because the program has viewed over all possible team combinations (approx 3 lakh - 4 lakh possible teams) <br/>
2. You can just make some tweaks to one of the best 5 teams that you find promising(based on form of a player,based on pitch , etc). <br/>
3. Irrespective of the tournament(BBL,CWC,t20 CWC,etc),if you can create a database(csv file) at the start of the tournament in the format of STATS.csv, this code can be used along with that database too. (As the constraints remain same so the algorithm/code remains same)<br/>

Drawbacks of this project:
--------------------------
1. The main drawback of this code is that it can't recognize so-called "form" of a player.<br/>
2. Dream11 is mainly based on luck,<br/>
   and this code(even an enchanced version of this one) can't predict such luck based instances.<br/>
   
Next Steps:
--------------------------
1. The next possible step is to improve efficiency of the algorithm which we use to estimate average points of a player.<br/>
2. Ball by Ball stats from the past 10-15 yrs can be used along with ML models to enhance the construction of the database, with more accurate values.<br/>

# Thank You Note:
This is my first solo project based on my ideas,<br/>
I would like to thank<br/>
1) iplt20.com and Google for providing stats<br/>
2) geeksforgeeks.com for using makeCombi function (from line 53 to line 73 in the code)<br/>
3) BVS Sudhindra and shivaram_22 from codeforces for brilliant insights and ideas when I was coding this project.<br/>
