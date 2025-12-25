function valid() {
    var a = document.getElementById('uname').value; // Moved inside function

    if (a == "") {
        document.getElementById('ername').innerHTML = "Username is required.";
        return false;
        alert("hi")
    }
}
