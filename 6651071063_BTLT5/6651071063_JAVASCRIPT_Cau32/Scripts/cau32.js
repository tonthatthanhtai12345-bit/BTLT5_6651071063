function display_random_image() {
  var ds = [
    { src: "http://farm4.staticflickr.com/3691/11268502654_f28f05966c_m.jpg", w: "240", h: "160" },
    { src: "http://farm1.staticflickr.com/33/45336904_1aef569b30_n.jpg", w: "320", h: "195" },
    { src: "http://farm6.staticflickr.com/5211/5384592886_80a512e2c9.jpg", w: "500", h: "343" }
  ];
  var r = ds[Math.floor(Math.random() * ds.length)];
  var img = document.createElement("img");
  img.src = r.src; img.width = r.w; img.height = r.h;
  var box = document.getElementById("anh");
  box.innerHTML = "";
  box.appendChild(img);
}
