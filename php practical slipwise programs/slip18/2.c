HTML file :
 <html> 
<body> 
<form action="slip18_2_1.php" method="get">
 <center> 
 <h2>Enter Enployee Details :</h2>  <br>  
<table> 
<tr>  <td><b>Emp no :</b></td><td><input type=text name=eno></td></tr>
 <tr>  <td><b> Name :</b></td><td><input type=text name=enm></td></tr> 
<tr><td><b>Address :</b></td><td><input type=text name=eadd></td></tr>
 </table> 
<br><input type=submit value=Show name=submit> 
</center> 
</form> 
</body> 
</html>
-------------------------------------------------------------   
PHP file : slip_18_2_1.php
 <?php
 session_start();
 $eno = $_GET['eno']; 
$enm = $_GET['enm'];   
$eadd = $_GET['eadd'];  
$_SESSION['eno'] = $eno; 
$_SESSION['enm'] = $enm;
 $_SESSION['eadd'] = $eadd; 
?> 
 
<html> <body>  
<form action="slip18_2_2.php" method="post">
 <center>
 <h2>Enter Earnings of Employee:</h2>  
<table>
 <tr><td>Basic : </td><td><input type="text" name="e1"></td></tr> 
<tr><td>DA : </td><td><input type="text" name="e2"></td></tr>
 <tr><td>HRA : </td><td><input type="text" name="e3"></td></tr> 
<tr><td></td><td><input type="submit" value=Next></td></tr> 
</table>
 </center>
 </form> 
</body>
 </html> 
------------------------------------------------------- 
PHP file : slip18_2_2.php
 <?phps
 session_start();
 $e1 = $_POST['e1'];
 $e2 = $_POST['e2'];
 $e3= $_POST['e3'];    
echo "<h3>Employee Details</h3> "; 
echo "Name : ".$_SESSION['eno']."<br>"; 
echo "Address : ".$_SESSION['enm']."<br>"; 
echo "Class : ".$_SESSION['eadd']."<br><br>";  
echo "basic : ".$e1."<br>"; echo "DA : ".$e2."<br>"; 
echo "HRA : ".$e3."<br>";  
$total = $e1+$e2+$e3;
 echo "<h2>Total Of Earnings Is : ".$total."</h2>";  
?>  