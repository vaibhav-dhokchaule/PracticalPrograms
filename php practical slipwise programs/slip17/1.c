HTML file : 
<html>
 <body>  
<center>
 <h2> Check Given String Is Palindrom Or Not</h2> 
<form action="slip17_1.php" method="GET"> 
<h3>   Enter String : <input type=text name=str><br>  </h3> 
<input type=submit value=submit name=Show>
 <input type=reset value=Reset name=Reset>
 </form>
 </center>
 </body>
 <html> 
----------------------------------------------------------------- 
PHP file :
 <?php
 $str1 = $_GET['str']; 
 $str2 = strrev($str1);  
if(strcmp($str1,$str2) === 0) 
 echo "<h3> $str1 is palindrom </h3>"; 
  else echo "<h3> $str1 is not palindrom </h3>";
 ?>  
