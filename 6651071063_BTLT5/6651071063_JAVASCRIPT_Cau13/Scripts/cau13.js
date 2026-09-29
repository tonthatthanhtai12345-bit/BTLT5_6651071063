function laNguyenTo(x) {
  if (x < 2) return false;
  for (var i = 2; i * i <= x; i++) if (x % i === 0) return false;
  return true;
}
var n = parseInt(prompt("Nhập n:", 50));
var ds = [];
for (var i = 2; i < n; i++) if (laNguyenTo(i)) ds.push(i);
document.getElementById("kq").innerText = "Các số nguyên tố nhỏ hơn " + n + ": " + ds.join(", ");
