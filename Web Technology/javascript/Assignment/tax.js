function calculateTax(income, isFemaleOrMarried = false) {
    let tax = 0;
    let minTaxable = isFemaleOrMarried ? 600000 : 500000; // Adjusting minimum taxable amount

    if (income <= minTaxable) {
        tax = income * 0.01; // 1% tax
    } else if (income <= 800000) {
        tax = minTaxable * 0.01 + (income - minTaxable) * 0.10; // 1% on minTaxable, 10% on remaining
    } else if (income <= 1500000) {
        tax = minTaxable * 0.01 + 300000 * 0.10 + (income - 800000) * 0.20; // 20% for 8-15 lakh
    } else if (income <= 2400000) {
        tax = minTaxable * 0.01 + 300000 * 0.10 + 700000 * 0.20 + (income - 1500000) * 0.30; // 30% for 15-24 lakh
    } else {
        tax = minTaxable * 0.01 + 300000 * 0.10 + 700000 * 0.20 + 900000 * 0.30 + (income - 2400000) * 0.39; // 39% above 24 lakh
    }

    return tax;
}

// Example Usage
let income = parseFloat(prompt("Enter your annual income:"));
let isFemaleOrMarried = confirm("Are you a female or married individual?");
alert("Your calculated tax is: Rs. " + calculateTax(income, isFemaleOrMarried).toFixed(2));
