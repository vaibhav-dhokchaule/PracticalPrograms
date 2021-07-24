XML file : book.xml
 <?xml version='1.0' encoding ='UTF-8' ?> 
<?xml-stylesheet type="text/css"?>   
<bookstore> 
 <books category="technical">   
<book_no>1</book_no> 
  <book_name>def</book_name> 
  <author_name>xxx</author_name> 
  <price>100</price> 
  <year>1990</year> 
 </books> 
 <books category="Cooking"> 
  <book_no>2</book_no> 
  <book_name>ccc</book_name> 
  <author_name>aaa</author_name>  
 <price>200</price>  
 <year>1950</year> 
 </books> 
 <books category="YOGA"> 
  <book_no>3</book_no> 
  <book_name>ddd</book_name> 
  <author_name>zzz</author_name> 
  <price>150</price> 
  <year>2016</year> 
 </books>
  <books category="technical">  
 <book_no>1</book_no>  
 <book_name>def</book_name> 
  <author_name>xxx</author_name> 
  <price>100</price>  
 <year>1990</year> 
 </books> 
 <books category="technical">  
 <book_no>1</book_no> 
  <book_name>def</book_name> 
  <author_name>xxx</author_name>  
 <price>100</price> 
  <year>1990</year> 
 </books> 
</bookstore>  
---------------------------------------------------
PHP file :
 <?php 
 $doc=new DOMDocument
$doc->load("book.xml"); 
 $name=$doc->getElementsByTagName("book_name"); 
 $year=$doc->getElementsByTagName("year");  
 echo "Books Names"; 
 foreach($name as $val) 
 {  
 echo "<br>".$val->textContent; 
 } 
 echo "<br><br> Year"; 
 foreach($year as $value)
  {  
  echo "<br>".$value->textContent; 
 }
 ?>  
