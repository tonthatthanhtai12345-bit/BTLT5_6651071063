var sel = document.getElementById("thang");
for (var i = 1; i <= 12; i++) sel.options.add(new Option(i, i));
function xuatThu() {
  var d = parseInt(document.getElementById("ngay").value);
  var m = parseInt(document.getElementById("thang").value);
  var y = parseInt(document.getElementById("nam").value);
  var dt = new Date(y, m - 1, d);
  if (isNaN(d) || isNaN(y) || dt.getDate() !== d || dt.getMonth() !== m - 1) {
    document.getElementById("kq").innerText = "Ngày tháng năm không hợp lệ!";
    return;
  }
  var t = dt.getDay();
  var thu = (t === 0) ? "Chủ nhật" : "Thứ " + (t + 1);
  document.getElementById("kq").innerText = thu + " Ngày " + d + " tháng " + m + " năm " + y;
}
