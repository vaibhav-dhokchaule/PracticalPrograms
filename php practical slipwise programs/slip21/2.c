HTML file : 
<html>
 <body>
 <form action="slip21_2_1.php" method="get">
 <center> 
 <b>Select font style :</b><input type=text name=s1> 
<br> <b>Enter font size : </b><input type=text name=s>
<br> <b>Enter font color : </b><input type=text name=c><br>
 <b>Enter background color :</b> <input type=text name=b>
<br> <input type=submit value="Next">
 </center> 
</form>
 </body>
 </html>  
----------------------------------------------------------------------------
PHP file : slip21_2_1.php
 <?php
 echo "style is ".$_GET['s1']."
<br>color is ".$_GET['c']."
<br>Background color is ".$_GET['b']."
<br>size is ".$_GET['s']; 
setcookie("set1",$_GET['s1'],time()+3600);
 setcookie("set2",$_GET['c'],time()+3600);
 setcookie("set3",$_GET['b'],time()+3600);
 setcookie("set4",$_GET['s'],time()+3600);
 ?>  

<html>
 <body>
 <form action="slip21_2_2.php">
 <input type=submit value=OK> 
</form>
 </body>
 </html>
---------------------------------------------   
PHP file : slip21_2_2.php 
<?php
 $style = $_COOKIE['set1'];
 $color = $_COOKIE['set2'];
 $size = $_COOKIE['set4'];
 $b_color = $_COOKIE['set3']; 
$msg = "NR Classes";
 echo "<body bgcolor=$b_color>";
 echo "<font color=$color size=$size>$msg";
 echo "</font></body>";
 ?>     
 