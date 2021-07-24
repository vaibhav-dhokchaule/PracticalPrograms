HTML file :
 <html> 
<body> 
<form action=slip11_2.php method="get"> 
Enter Employee No. :<input type=text name=e_no><br>
 Enter Employee Name :<input type=text name=e_nm><br> 
Enter Employee Address :<input type=text name=e_addr><br> 
Enter Employee Phone No. :<input type=text name=e_ph><br> 
Enter Employee Salary :<input type=text name=e_sal><br> 
Enter Dept No. :<input type=text name=d_no><br> 
Enter Dept Name :<input type=text name=d_nm><br> 
Enter Dept Location :<input type=text name=d_loc><br> 
<input type=radio name="op" value="1" >Insert  
Enter Dept Name :<input type=text name=d_name><br>
 <input type=radio name="op" value="2" >Display 
</form> 
</body>
 </html> 
---------------------------------------------------------------------------------- 
PHP file :
 <?php
  $con_string="host = localhost dbname=bcs_slips port=5432  user=postgres password=nrc";
  $con = pg_connect($con_string);  
 $op = $_GET['op']; 
 switch($op) 
 {  
 case 1 : 
$e_no = $_GET['e_no'];   
 $e_nm = $_GET['e_nm'];   
 $e_addr = $_GET['e_addr'];  
  $e_ph = $_GET['e_ph'];   
 $e_sal = $_GET['e_sal'];   
 $d_no = $_GET['d_no'];   
 $d_nm = $_GET['d_nm'];   
 $d_loc = $_GET['d_loc'];   
 $q = "insert into dept values($d_no,'$d_nm','$d_loc')";   
 $q1 = "insert into emp values($e_no,'$e_nm','$e_addr',$e_ph,$e_sal,$d_no)";     
   echo "Details of Employye are inserted ";  
  break;     
    case 2 : 
$d_name = $_GET['d_name'];  
  $q = "select MAX(emp_sal),MIN(emp_sal),SUM(emp_sal) from dept,emp where dept_name='$d_name' and emp.dept_no = dept.dept_no;";  
  $rs = pg_query($con,$q) ;   
 if($rs)  
  {  
   while($row=pg_fetch_row($rs))    
 {     
 echo "<table align=center border=1>";      
echo "<tr><td>Maximum Sal</td><td>Minimum Sal</td><td>Sum Sal</td></tr>";   
   echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td></tr>";    
  echo "</table>";   
   }  
   }     
break;
  }  
pg_close();
 ?> 