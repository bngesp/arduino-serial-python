<?php

require 'function.php';

if (isset($_GET['temperature'])) {

	saveData($_GET['temperature']);
}
else {
	echo '<table><thead><th>Id</th><th>valeur</th><th>date</th></thead>';
	foreach (getAllData() as $key => $valeur) {
		echo "<tr><td>".$valeur['id']."</td><td>".$valeur['valeur']."</td><td>".$valeur['date']."<td></tr>";
	}
	echo "</table>";

}