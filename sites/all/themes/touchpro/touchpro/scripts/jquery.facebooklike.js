/* Handling width of facebook like plugin */
jQuery(window).load(function () {
	//Manipulate facebook box width. Since the iframe has no ID i need to match on the source attribute
	var facebookIframe = new Array();
	facebookIframe = jQuery('iframe');
	for(var i=0;i<facebookIframe.length;i++){
		var facebookMatch=facebookIframe[i].src.match(/facebook/g);
		if (facebookMatch !== undefined) {
			facebookIframe[i].setAttribute("style","border:none; overflow:hidden; width:100%; height:690px;");
		}
	}
});