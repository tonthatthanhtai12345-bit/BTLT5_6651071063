function tinh(pt) {
  var a = parseFloat(document.getElementById("so1").value);
  var b = parseFloat(document.getElementById("so2").value);
  var kq;
  if (isNaN(a) || isNaN(b)) kq = "Vui lòng nhập hai số hợp lệ!";
  else if (pt === "nhan") kq = a * b;
  else kq = (b === 0) ? "Không thể chia cho 0!" : a / b;
  document.getElementById("kq").innerText = kq;
}
