# statistics
Statistics is a menu driven program, that has 9 options of menu. 
## Users’ manual 
 The program is able to take several inputs through keyboard and file handling. Initially, when the user 
has not entered input, the program will show such options: 
1. Text input from file – this menu is for take input from text file. First, the user need to type the 
   file path that he wants to take input from. 
2. Text input from keyboard – here user can type text from keyboard as an input to the program. 
0. Exit – to exit. 
8. History – if the user choose this one, he can see all history of the program. (what were outputs, 
   what were input, and the date) 
   Once, the user entered some input, the program will show such options additionally: 
3. The longest word – to find the first longest word from the input that the user entered. 
4. The shortest word – to find the first shortest word from the input that the user entered. 
5. Occurrence – if the user choose this option, the program will want the user to enter a word that 
   to be counted its occurrence. When the user entered the word, the program will show an 
   occurrence of the word. 
6. Most occurred – this is to find the first word that most occurred from the input.(if both of the 
   words ‘if’ and ‘is’ occurred most times, the program will return one of them depending on their 
   position. If the word ‘if’ appears first, the result will be the word ‘if’. 
7. Least occurred – to find the first word that occurred least times. 
Furthermore, the program is able to write every result and the date into a file called ‘history’. 
Data structures, design considerations 
The program controls the menu using switch statement and store words into database using linked list. 
That is the way the result written into the ‘history’ file: 
Description of the functions 
Description of the every function is written in the c code as a comment.
