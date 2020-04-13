// Code Written by Rishi Tiwari
// Website:- https://tricksumo.com

<?php



    $host = "localhost";		         // host = localhost because database hosted on the same server where PHP files are hosted
    $dbname = "sumodb";              // Database name
    $username = "sumouser";		// Database username
    $password = "Tr[~b>)wwac6Ze~G";	        // Database password


// Establish connection to MySQL database
$conn = new mysqli($host, $username, $password, $dbname);


// Check if connection established successfully
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

else { echo "Connected to mysql database. <br>"; }


// Select values from MySQL database table

$sql = "SELECT id, val, val2, date, time FROM tricksumo_nodemcu";  // Update your tablename here

$result = $conn->query($sql);

echo "<center>";



if ($result->num_rows > 0) {


    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "<strong> Id:</strong> " . $row["id"]. " &nbsp <strong>val:</strong> " . $row["val"]. " &nbsp <strong>val2:</strong> " . $row["val2"]. " &nbsp <strong>Date:</strong> " . $row["date"]." &nbsp <strong>Time:</strong>" .$row["time"]. "<p>";
    


}
} else {
    echo "0 results";
}

echo "</center>";

$conn->close();



?>
