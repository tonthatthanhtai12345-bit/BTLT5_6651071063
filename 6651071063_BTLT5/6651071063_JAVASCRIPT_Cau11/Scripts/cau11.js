function daoNguoc(n) {
  var r = 0;
  while (n > 0) {
    r = r * 10 + n % 10;
    n = Math.floor(n / 10);
  }
  return r;
}
var n = 654321;
document.getElementById("kq").innerText = n + " => " + daoNguoc(n);
