function luyThua(b, n) {
  var kq = 1;
  for (var i = 0; i < n; i++) kq *= b;
  return kq;
}
var b = 2, n = 10;
document.getElementById("kq").innerText = b + "^" + n + " = " + luyThua(b, n);
