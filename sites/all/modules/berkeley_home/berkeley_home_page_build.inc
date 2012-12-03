<?php
/**
* @file
*
* Build homepage
*
*/

function berkeley_home_page_build(){

	// Init vars
	$module_path = drupal_get_path('module','berkeley_home');
	$html = '';

	// Adding javascript
	$js_path = "$module_path/js/jquery.easing.1.3.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 1));
	$js_path = "$module_path/js/init.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 10));
	$js_path = "https://maps.google.com/maps/api/js?sensor=false";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 2));
	$js_path = "$module_path/js/jquery.stellar.min.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 3));
	
	
	 // Build MySQL Query Statement
  $about_query_string = "
     SELECT about_page_text, about_page_vimeo_id, id
      FROM cirro_about_page
      WHERE id = 1
  ";
  

  // Use drupal's db_query function 
  // $about_query = db_query( $about_query_string );
  // $about_items = $about_query->fetchAssoc();

  $about = "
  	<div id=\"store\" class=\"text-center\">
  		<div class=\"container\">
  			<h1>Store</h1>
  			<p>Yo this is the store, what of it</p>
  		</div>
  	</div>
  ";

  $scroller = "
  	<img src=\"/sites/all/themes/clim/images/wood.jpg\" />
  ";

  // $scroller = "
  // 	<div id=\"main-scroller\"></div>
  // ";

  $brands = "
  	<div id=\"brands\" class=\"text-center\">
  		<div class=\"container\">
  			<h1>Brands</h1>
  			Here are the brands
  		</div>
  	</div>
  ";

  $footer = "
  	<footer id=\"footer\" class=\"text-center\">
		  <div class=\"container\">
		    <div id=\"address\">
		      <h1>Contact</h1>
		      4405 West 43rd Ave </br>
		      Denver, Colorado 80212
		    </div>
		    <div id=\"phone\">
		      603 . 315 . 3187
		    </div>
		    <div id=\"social\">
		    </div>
		  </div>
		</footer> 
  ";

  $map = "
  	 <div id=\"map_canvas\" style=\"width:100%; height:100%\"></div>
  ";

	$html = "
		<div class=\"content\">
			$scroller
			$about
			$brands
			$footer
			$map
		</div>
	";
	

	return $html; 

}