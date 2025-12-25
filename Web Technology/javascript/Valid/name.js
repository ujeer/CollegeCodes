function showMessage(location, message, color) {
    document.getElementById(location).innerHTML = message;
    document.getElementById(location).style.color = color;
}

function namevalid() {  // Changed function name for consistency
    var name = document.getElementById("name").value;

    if (name == "") {
        showMessage("errname", "Name is required", "red");
    } 
    else if (name.length < 3) {
        showMessage("errname", "3 or more characters needed", "orange");
    } 
    else if (!name.match(/^[A-Za-z]{3,30}\s[A-Za-z]{3,30}$/)) {
        showMessage("errname", "Enter first name, one space, and last name", "blue");
    } 
    else {
        showMessage("errname", "Valid name", "green");
    }
}

function validphone() {
    var phone = document.getElementById("pnum").value;

    if (phone == "") {
        showMessage("errphone", "This field cannot be empty", "red");
    } 
    else if (!phone.match(/^[0-9]+$/)) {  // Fixed regex (ensures only numbers)
        showMessage("errphone", "Enter numbers only", "red");
    } 
    else if (!phone.startsWith("98")) {  // Fixed prefix check
        showMessage("errphone", "First two digits must be 98", "orange");
    } 
    else if (phone.length != 10) {  
        showMessage("errphone", "Enter exactly 10 digits", "blue");
    } 
    else {
        showMessage("errphone", "Valid phone", "green");
    }
}