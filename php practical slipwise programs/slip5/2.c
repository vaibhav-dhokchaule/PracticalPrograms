XML file :  employee.xml

 <?xml version="1.0" encoding="UTF-8"?>
 <Empdetails>
  <Emp Empno="1" Empname="Mansi">  
 <Sal>15000</Sal>  
 <Desg>Developer</Desg>  
</Emp>
  <Emp Empno="2" Empname="Gautam">  
 <Sal>35000</Sal> 
  <Desg>HR</Desg>
 </Emp> 
 <Emp Empno="3" Empname="Jack">  
 <Sal>25000</Sal>  
 <Desg>Tester</Desg> 
 </Emp>
 </Empdetails> 
------------------------------------------------------------------ 
PHP file :
 <?php  $xml=simplexml_load_file("employee.xml") or die("eror:cannot create object");  
 echo "<table border=1 align=center>"; 
 echo "<tr><td>Employee no</td><td>Employee Name</td><td>Employee Salary</td><td>Employee Employee Designation</td></tr>";  
 foreach($xml->children() as $emp)
  {  
 $arr = $emp->attributes();  
   echo "<tr><td>".$arr["Empno"]."</td>"; 
  echo "<td>".$arr["Empname"]."</td>"; 
  echo "<td>".$emp->Sal."</td>";  
 echo "<td>".$emp->Desg."</td></tr>";  
   }  
 echo "<table>";
 ?>  
