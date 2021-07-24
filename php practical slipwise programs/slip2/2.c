HTML file : 
<html> 
<body> 
<form action="slip2_Q2.php" method="POST">
 <center> 
<h1>Search file of given extension</h1>
 <h3>Enter directory name : <input type="text" name="dir"></h3>
 <h3>Enter file extension : <input type="text" name="ex"></h3>
 <input type="submit" name="submit" value="submit">
<input type="reset" name="reset" value="reset">
 </center> 
</form>
 </body>
 </html> 
-----------------------------------------------------   
PHP file :
 <?php
  $d=$_POST['dir'];
  $e=$_POST['ex'];  
   if(is_dir($d)) 
 {  
 $h=opendir($d);   
   echo "<h3> the files with extension $e in directory $d are :: </h3>";  
 while($file = readdir($h) !== false)  
 {
    if(is_dir($file))   
 continue;        
$ext=explode('.',$file);   
 if($ext[1] == $e)   
 echo "<h3> $file </h3><br>"; 
    }  
  }  
 ?>  
