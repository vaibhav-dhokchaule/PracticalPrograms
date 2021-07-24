HTML file :
 <html>
 <body> 
<FORM ACTION="slip19_1.php" method="GET">
 <table>
 <tr><td><h3>Enter Email Address :</td><td><input type=text name=eid ></h3></td></tr>  
<tr><td></td><td><input type=submit name=submit value=Validate></td></tr> 
</table>
 </form> 
 </body>
 </html> 
------------------------------------------- 
PHP file :
 <?php
 $eid=$_GET['eid'];
 if((!empty($eid)))
 {   
if(ereg("^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)$",$eid)) 
  echo "<h2>VALID EMAILID</h2>";  
  else echo "<h2>INVALID EMAILID</h2>"; 
}
 else echo "<h2>Plz enter Email Address</h2>";
 ?>  