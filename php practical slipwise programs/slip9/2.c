HTML file :
 <html>
 <body> 
<form action=slip9_2.php>
 Enter Compitition Name :<input type=text name=a id=a><br>
 <input type=submit value="DISPLAY" >
 </form>   
</body>
 </html> 
---------------------------------------------------- 
PHP file : 
<?php
 $con_string="host=localhost dbname=bcs_slips port=5432  user=postgres password=nrc"; 
$con=pg_connect($con_string);  
$a=$_GET['a'];
 echo $a;
 echo "</br>";
 $q="select student.stud_id,sname,class from student,competition,stud_copm  where cnme='$a' and student.stud_id=stud_copm.stud_id and competition.c_no=stud_copm.c_no;";
 $rs=pg_query($con,$q) or die("Cannot Execute query"); 
while($row=pg_fetch_row($rs)) echo "$row[0] $row[1] $row[2]\n</br>";  
pg_close(); 
?>  