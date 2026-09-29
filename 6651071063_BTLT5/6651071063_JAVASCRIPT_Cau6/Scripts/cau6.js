var a = parseFloat(prompt("Nhập a:"));
var b = parseFloat(prompt("Nhập b:"));
var c = parseFloat(prompt("Nhập c:"));
var kq;
if (a === 0) {
  if (b === 0) kq = (c === 0) ? "Phương trình vô số nghiệm." : "Phương trình vô nghiệm.";
  else kq = "Phương trình có nghiệm duy nhất x = " + (-c / b);
} else {
  var d = b * b - 4 * a * c;
  if (d < 0) kq = "Phương trình vô nghiệm.";
  else if (d === 0) kq = "Nghiệm kép x1 = x2 = " + (-b / (2 * a));
  else kq = "Hai nghiệm phân biệt: x1 = " + ((-b + Math.sqrt(d)) / (2 * a)) + ", x2 = " + ((-b - Math.sqrt(d)) / (2 * a));
}
window.alert(kq);
