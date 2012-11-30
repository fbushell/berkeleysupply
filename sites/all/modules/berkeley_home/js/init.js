;(function( $, window, document, undefined ){
    
	$(document).ready(function(){	

		// Init
	 
		var	$window = $(window),
				$nav    = $('#nav a');

		// ----------------------------------------------------------
		// This scrolling is so damn smooth...mmmmmmm
		// ----------------------------------------------------------
		$(function(){

			$nav.on('click', function(event) {

				// Init
				var $link = $(this);

				// Scroll to href of clicked link
				$('html, body').stop().animate({

	          scrollTop: $($link.attr('href')).offset().top

	      }, 1500,'easeInOutExpo');

				event.preventDefault();

			});

		});


		$(function(){

			$.stellar();

		});

	});

}( jQuery, window, document));

