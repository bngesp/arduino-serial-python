<?php
/**
* Author : Bassirou NGOM
* date : 04/01/2019
* licence: MIT
*/


require_once '../vendor/autoload.php';

function sendmail($to, $objet, $msg){
	//creation du transport
	$trans = new Swift_SmtpTransport('smtp.gmail.com', 587,'tls');
	$transport =  $trans
					->setUsername('projetsettp@gmail.com')
					->setPassword('projetandtp2017');

	$mailer = new Swift_Mailer($transport);
	// Create a message
	$message = (new Swift_Message($objet))
	  ->setFrom(['projetsettp@gmail.com' => 'Monitoring System'])
	  ->setTo($to)
	  ->setBody($msg);

	// Send the message
	$result = $mailer->send($message);
	return $result;

}



function getDB()
{
	$dbname = 'tp_php';
	$dbUser = 'root';
	$dbPass = 'root';

	$bd = null;
	try {
		$bd =  new PDO("mysql:dbname=$dbname;host=127.0.0.1", $dbUser, $dbPass);
	} catch (Exception $e) {
		echo $e;
	}
	return $bd;
}



function saveData($data)
{
	$bd = getDB();
	$result = false;
	if(!is_null($bd)){
	
		$sql = "INSERT into temperature(valeur, date) VALUES(:valeur, :dat)";

		$element = $bd->prepare($sql);	
		$result = $element->execute(array(
			":valeur" => $data,
			":dat" => date('Y-m-d H:i:s')
		));
	}

	return $result;
}

function getAllData()
{
	$bd = getDB();
	$alluser = null;
	if(!is_null($bd)){
		$sql = "SELECT * from temperature";
		$element = $bd->query($sql);

		$alluser = $element->fetchAll(PDO::FETCH_ASSOC);
	}
	return $alluser;
	
}













