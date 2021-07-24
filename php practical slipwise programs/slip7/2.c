HTML file :
 <!DOCTYPE html>
 <html>
 <head>
 <title>Book Store</title>
 </head>
 <body>
 <form action="slip7_Q2.php" method="get"> 
<table>
 <tr><td><label> Enter 1st Book title Name : </label></td><td><input type="text" name="title_1" id="title_1"></td></tr>
 <tr><td><label> Enter 1st Book Publication Name : </label></td><td><input type="text" name="pub_1" id="pub_1"></td></tr>
 <tr><td><label> Enter 2st Book title Name : </label></td><td><input type="text" name="title_2" id="title_2"></td></tr>
 <tr><td><label> Enter 1st Book Publication Name : </label></td><td><input type="text" name="pub_2" id="pub_2"></td></tr>
 <tr><th colspan="2"><input id="ok" type="submit" value="OK" name="ok"></th></tr> 
</table> 
</form>
 </body>
 </html>  
 ------------------------------------------------------------------------
PHP file :
 <?php  $title_1 = $_GET['title_1'];
  $pub_1 = $_GET['pub_1']; 
 $title_2 = $_GET['title_2'];  
$pub_2 = $_GET['pub_2'];   
 $xml = "<?xml version='1.0' encoding ='ISO-8859-1' ?>"; 
 $xml = $xml."<BookStore>"; 
 $xml = $xml."<Books>";
   $xml = $xml."<PHP>"; 
  $xml = $xml."<Title>";  
 $xml = $xml."$title_1"; 
  $xml = $xml."</Title>";  
  $xml = $xml."<Publication>"; 
  $xml = $xml."$pub_1";  
 $xml = $xml."</Publication>";
  $xml = $xml."</PHP>"; 
 $xml = $xml."<PHP>"; 
  $xml = $xml."<Title>";  
 $xml = $xml."$title_2"; 
  $xml = $xml."</Title>"; 
  $xml = $xml."<Publication>";  
 $xml = $xml."$pub_2"; 
  $xml = $xml."</Publication>";
  $xml = $xml."</PHP>"; 
 $xml = $xml."</Books>";
  $xml = $xml."</BookStore>";
    if($fp = fopen("bookstore.xml","a+")) 
 { 
  if($wt = fwrite($fp,$xml))  
 {  
  header("location:bookstore.xml");
   }   
else "file not created..."; 
 } 
 else echo "file not open...."; 
  ?>  
 
