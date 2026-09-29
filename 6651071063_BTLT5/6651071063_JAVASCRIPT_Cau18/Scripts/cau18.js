function giaiThua(n) {
  n = Math.floor(Math.abs(n));
  var kq = 1;
  for (var i = 2; i <= n; i++) kq *= i;
  return kq;
}
var n = parseInt(prompt("Nhập n:", 5));
document.getElementById("kq").innerText = n + "! = " + giaiThua(n);
