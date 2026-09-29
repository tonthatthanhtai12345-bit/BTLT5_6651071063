// Công thức Heron
var a = 5, b = 6, c = 7;
var p = (a + b + c) / 2;
var s = Math.sqrt(p * (p - a) * (p - b) * (p - c));
console.log(s);
window.alert("The area of the triangle is: " + s.toFixed(2));
document.getElementById("ketqua").innerText = "The area of the triangle is: " + s.toFixed(2);
