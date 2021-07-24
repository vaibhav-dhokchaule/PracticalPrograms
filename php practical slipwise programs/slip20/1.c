HTML file : 
<html>
 <body>
 <form action=slip20_1.php method=get>
 <center> Full Name  :<input  type=text  name=nm>
 <br><input  type=submit  value=Show>
 </center> 
</form>
  </body> 
</html> 
--------------------------- 
PHP file : 
<?php 
 $nm=$_GET['nm']; 
 echo "<br>Capitalization of each word of each name :".ucwords($nm); 
 echo "<br>Whole String In Upper Case :".strtoupper($nm); 
?> 