<html> 
<head> 
<title>HTML email</title>
 </head> 
Send Mail    
<body>
 <form action=slip23_2.php> 
<table border=1>
 <tr><td>To<input type=text name=to></td></tr>
 <tr><td>subject<input type=text name=sub></td></tr>
 <tr> <td>Message<input type=textarea name=msg></td></tr>
 <tr> <td><input type=submit value="SEND MAIL"></td> </tr> 
</table> 
</form>
 </body>
 </html>  
-------------------------------------------------------------
PHP file : <?php $to = $_GET['to'];    
  $subject =  $_GET['sub'];   
  $message =  $_GET['msg'];
 mail($to,$subject,$message);       
?>   
