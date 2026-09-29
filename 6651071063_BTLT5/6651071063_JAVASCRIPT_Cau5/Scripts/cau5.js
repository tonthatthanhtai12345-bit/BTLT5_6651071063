var n = parseInt(prompt("Nhập một số nguyên dương:"));
function laNguyenTo(n) {
  if (isNaN(n) || n < 2) return false;
  for (var i = 2; i <= Math.sqrt(n); i++) if (n % i === 0) return false;
  return true;
}
window.alert(n + (laNguyenTo(n) ? " là số nguyên tố." : " không phải là số nguyên tố."));
