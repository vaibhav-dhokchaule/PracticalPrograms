Dat file : student.dat 
1 Ajay 50 20 80 
2 Vijay 30 80 60  
------------------------------------------
HTML file :
 <html>
 <body> 
<center> 
<h2> student Details</h2>
 <form action="slip16_2.php" method="GET"> 
<h2>   Reading File In Tabular Format : </h2>
 <h3>   Enter Directory Name : <input type=text name=d><br><br>  </h3> 
<pre> <input type=submit value=submit name=Show> 
<input type=reset value=Reset name=Reset> </pre>
 </form> 
</center> 
</body>
 </html>
-----------------------------------------------------------  
PHP file : 
<?php 
if(file_exists('student.dat'))
 {  
 $f = fopen('student.dat','r');   
echo "<br><br>";  
  echo "<table border type=3 align=center>";   
echo "<tr><td align=center>Roll No</td>";   
echo "<td align=center> Name</td>";  
 echo "<td align=center> Maths</td>";  
 echo "<td align=center> Science</td>";  
 echo "<td align=center> Computer</td>"; 
  echo "<td align=center> Total</td>";  
 echo "<td align=center> Percentage</td></tr>";  
  while(!feof($f))  
 {    
$d = fgets($f);   
 $s = explode(' ',$d);  
      if(!empty($s[0]) && !empty($s[1]) && !empty($s[2]) && !empty($s[3]) && !empty($s[4]))   
 {      
 $m1 = $s[2];    
 $m2 = $s[3];    
 $m3 = $s[4];    
 $total = $m1+$m2+$m3;    
 $p = ($total/300)*100;  
  echo "<tr><td align=center>$s[0]</td>";    
 echo "<td align=center> $s[1]</td>";    
 echo "<td align=center> $m1</td>";    
 echo "<td align=center> $m2</td>";    
 echo "<td align=center> $m3</td>";     
echo "<td align=center> $total</td>";     
echo "<td align=center> $p</td></tr>";    
}   
}
 echo "</table>";
 }
 ?>  