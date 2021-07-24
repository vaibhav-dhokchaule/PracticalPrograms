HTML file :
 <html> 
<body>
 <form action=slip9_Q1.php method=get>
 <center>
 <br>Email ID :<input type=text  name=eid> 
<br><input  type=submit  value=Show>
 </center> 
</form>
 </body>
 </html>  
------------------------------------------
PHP file :
 <?php 
 $eid=$_GET['eid']; 
 $e=explode('@',$eid);  
  if (count($e)>=2)  
echo "<br>Email id contains @ symbol ";  
  else       
 echo "<br>email id does not contains  @ symbol";
  ?> 