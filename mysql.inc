<?php
class mysql{
	public $database;
	public $server_username;
	public $server_userpassword;
	function mysql(){
	$this->server_username="root";
	$this->server_userpassword="123456";
	}
	function link($database)
	{
		if($database=="")
		{
		$this->database="bbs_data";
		}
		else
		{
		$this->database=$database;
		}
		$id=mysqli_connect("127.0.0.1",$this->server_username,$this->server_userpassword,$this->database);
		if(!$id)
		{
		echo "链接数据库失败";
		exit;
		}
	}	
	function excu($query){
		if($result=mysqli_query($query)){
		return $result;
		}
		else
		{
		echo "sql语句执行错误！！请重试！！！";
		exit;
		}
	}
}
?>
