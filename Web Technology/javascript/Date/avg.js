// Function to calculate the mean of three numbers
function avg(a, b, c) {
    return (a + b + c) / 3;
}

// Function to calculate the mean of four numbers
function avg1(a, b, c, d) {
    return (a + b + c + d) / 4;
}

// Function to calculate the product of avg() and avg1()
function avg2(x1, x2, x3, y1, y2, y3, y4) {
    let mean3 = avg(x1, x2, x3); // Calling avg() for three numbers
    let mean4 = avg1(y1, y2, y3, y4); // Calling avg1() for four numbers
    return mean3 * mean4; // Returning the product of both means
}

// Taking user input
let x1 = parseFloat(prompt("Enter first number for avg():"));
let x2 = parseFloat(prompt("Enter second number for avg():"));
let x3 = parseFloat(prompt("Enter third number for avg():"));

let y1 = parseFloat(prompt("Enter first number for avg1():"));
let y2 = parseFloat(prompt("Enter second number for avg1():"));
let y3 = parseFloat(prompt("Enter third number for avg1():"));
let y4 = parseFloat(prompt("Enter fourth number for avg1():"));

// Calculating and displaying the result
let result = avg2(x1, x2, x3, y1, y2, y3, y4);
console.log("The product of the two averages is: " + result);
alert("The product of the two averages is: " + result);
