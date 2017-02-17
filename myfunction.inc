<?php
class myfunction{
	function str_to($str){
	$str=str_replace(" ","&nbsp;",$str);
	$str=str_replace("<","&lt;",$str);
	$str=str_replace(">","&gt;",$str);
	$str=nl2br($str);
	return $str;
	}
	function son_module_idtonote_num($son_module_id){
	$aa=new mysql;
	$aa->link("");
	$query="select * from note_info where module_id='".$son_module_id."'and up_id='0'";
	$rst=$aa->excu($query);
	return mysqli_num_rows($rst);
	}
	function son_module_idtonote_num2($son_nodule_id){
	$aa=new mysql;
	$aa->link("");
	$query="select * from note_info where module_id='".$son_module_id."' and up_id='0'";
	$rst=$aa->excu($query);
	$num=mysqli_num_rows($rst);
	while($note=mysqli_fetch_array($rst,MYSQL_ASSOC)){
	$query="select * from note_info where up_id='".$note['id']."' and module_id='0'";
	$rst=$aa->excu($query);
	$num+=mysqli_num_rows($rst);
	}
	return $num;
	}
	function son_module_idtolast_note($son_nodule_id){
	$aa=new mysql;
	$aa->link("");
	$query="select * from note_info where module_id='".$son_module_id."' order by time desc limit 0,1";
	$rst=$aa->excu($query);
	$note=mysqli_fetch_array($rst,MYSQL_ASSOC);
	$query2="select * from note_info where id='".$note['up_id']."'";
	$rst2=$aa->excu($query);
	$note2=mysqli_fetch_array($rst2,MYSQL_ASSOC);
	echo $note2['title']."<br/>";
	echo $note['time'].'  '.$note['user_name'];
	}
	function son_module_idtolast_name($son_nodule_id){
	$aa=new mysql;
	$aa->link("");
	$query="select * from note_info where module_id='".$son_module_id."'";
	$rst=$aa->excu($query);
	$module=mysqli_fetch_array($rst,MYSQL_ASSOC);
	if($module['user_name']=="")
	{
	return "版主暂缺";
	}
	else
	{return $module['user_name'];}
	}
	function son_module_list($son_nodule_id){
        $aa=new mysql;
        $aa->link("");
        $query="select * from father_module_info order by id";
        $rst=$aa->excu($query);
	echo "<select name=module_id>";
        while($father_module=mysqli_fetch_array($rst,MYSQL_ASSOC)){
        echo "<option value=>".$father_module['module_name']."</option>";//此处的<有问题
        $query2="select * from son_module_info where father_module_id='".$father_module['id']."' order by id";
        $rst2=$aa->excu($query2);
        while($son_module=mysqli_fetch_array($rst2,MYSQL_ASSOC)){
        echo "<option value=".$son_module['id'].">&nbsp;&nbsp;".$son_module['module_name']."</option>";
	}
	}
	echo "</select>";
	}
	function father_module_list($father_nodule_id){
        $aa=new mysql;
        $aa->link("");
        echo "<select name=father_module_id>";
	if($father_module_id==""){
	echo "<option selected>请选择...</option>";
	}
	else
	{
	 $query="select * from father_module_info where id='father_module_id'";
        $rst=$aa->excu($query);
        $father_module=mysqli_fetch_array($rst,MYSQL_ASSOC);
	echo "<option value=".$father_module['id'].">".$father_module['module_name']."</option>";
	}
        $query="select * from father_module_info  order by show_order";
        $rst=$aa->excu($query);
        while($father_module=mysqli_fetch_array($rst,MYSQL_ASSOC)){
        echo "<option value=".$father_module['id'].">".$father_module['module_name']."</option>";
        }
        echo "</select>";
        }
	function note_idtotimes($note_id){
        $aa=new mysql;
        $aa->link("");
        $query="select * from note_info where id='".$note_id."'";
        $rst=$aa->excu($query);
        $note=mysqli_fetch_array($rst,MYSQL_ASSOC);
	return $note['times'];
        }
	function note_idtotitle($note_id){
        $aa=new mysql;
        $aa->link("");
        $query="select * from note_info where id='".$note_id."'";
        $rst=$aa->excu($query);
        $note=mysqli_fetch_array($rst,MYSQL_ASSOC);
        return $note['title]'];
        }
	function note_idto_num($note_id){
        $aa=new mysql;
        $aa->link("");
        $query="select * from note_info where up_id='".$note_id."'";
        $rst=$aa->excu($query);
        $num=mysqli_num_rows($rst);
        return $num+1;
        }
	function note_idtolast_time($note_id){
        $aa=new mysql;
        $aa->link("");
        $query="select * from note_info where id='".$note_id."' order by time desc limit 0,1";
        $rst=$aa->excu($query);
        $note=mysqli_fetch_array($rst,MYSQL_ASSOC);
        return $note['time'];
        }
	function note_idtolast_user_name($note_id){
        $aa=new mysql;
        $aa->link("");
        $query="select * from note_info where id='".$note_id."'order by time desc limit 0,1";
        $rst=$aa->excu($query);
        $note=mysqli_fetch_array($rst,MYSQL_ASSOC);
        return $note['user_name'];
        }
	function son_module_idtofather_name($son_module_id){
        $aa=new mysql;
        $aa->link("");
        $query="select * from son_module_info where id='".$son_module_id."'";
        $rst=$aa->excu($query);
        $module=mysqli_fetch_array($rst,MYSQL_ASSOC);
        $query2="select * from father_module_info where id='$module[father_module_id]'";
        $rst2=$aa->excu($query2);
        $module2=mysqli_fetch_array($rst2,MYSQL_ASSOC);
	return $module2['module_name'];
        }
	





}
?>
