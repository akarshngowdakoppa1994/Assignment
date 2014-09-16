ASSIGNMENT 2


Name: Akarsha K N
USN : 1PI12IS006

Team member's Name:Mahesh Kumar
Team member's USN :1PI12IS049

Question No.: 3
Question Title: Write a “login” program for a user that asks the user to enter a user name and a password. The 
				use rname and password should have a matching entry in the file which has the data stored in 
				the following format:
				username1,password1
				username2,password2
				username3,password3
				...
				If the user name and password  matches an entry in the file, display a message saying “Welcome 
				<user name>!”.  If  a  matching  entry  is  not  found,  display  a  message  “Wrong 
				user name/password, please try again” and prompt the user to enter his/her credentials again. 
				Allow  a  maximum  of  up to  3  consecutive  incorrect  attempts  and  then  the  program  should 
				terminate  saying  “Maximum  attempts  exceeded”.  Consider  at  least  20  entries  in  the  file 
				containing user name and passwords.

				
->Solution for the above question contains two files asn3_3.c & Data.txt
->asn3_3.c contains the source code 
->Data.txt is a text file having stored data of user name & password .It is stored in the format (user name,password).We have stored 21 username and corresponing password.

->we have modified code of asn2_3.c slightly.
->modified code gives the same output as asn2_3.c and also it prints the last login time of the user if and only if  the login is successful.  
->format of file input is user name,password,last login time
->and our code modifies login time in the file after every successful login,which can be accessed on subsequent use.




>thank you