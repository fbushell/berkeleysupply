<?php
/**
* @file
*
* Build homepage
*
*/

function berkeley_home_page_build(){

	// Init vars
	$module_path  = drupal_get_path('module','berkeley_home');
	$brand        = '';
	$logo_grouped = '';
	$html         = '';
	$slider_imgs  = '';


	// Adding javascript
	$js_path = "$module_path/js/jquery.easing.1.3.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 1));
	$js_path = "$module_path/js/init.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 10));
	$js_path = "https://maps.google.com/maps/api/js?sensor=false";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 2));
	$js_path = "$module_path/js/jquery.stellar.min.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 3));
	$js_path = "$module_path/js/jquery.flexslider-min.js";
	drupal_add_js($js_path, array('scope' => 'footer', 'weight' => 3));

  // Build query for brands
  $brands_query_string = "
  	SELECT i.field_brand_logo_fid, i.delta, f.fid, f.uri
		FROM field_data_field_brand_logo AS i
		JOIN file_managed AS f
		ON i.field_brand_logo_fid = f.fid
		ORDER BY i.delta ASC
  ";
  
  // Use drupal's db_query function 
  $brands_query = db_query( $brands_query_string );
  $brand_items = $brands_query->fetchAll();

  // Loop through brands
  foreach ( $brand_items as $logo ) {

  	// Init
  	$logo_uri = $logo->uri;

  	$img_vars = array(
        'style_name' => 'logo',
        'path' => $logo_uri,
        'width' => '',
        'height' => '',
		);
		
		// Theme the image with the style
		$img_styled = theme_image_style($img_vars);

		$logo_final = $img_styled;

  	$brand .= "
  		<div class=\"brand-item\">
	  		$logo_final
	  	</div>
  	";

  }

	// Query for about text
	$about_query_string = "
		SELECT field_about_text_value
		FROM field_data_field_about_text
	";

	// Query for store images
	$store_query_string = "
		SELECT s.field_store_images_fid, s.delta, f.fid, f.uri
		FROM field_data_field_store_images AS s
		JOIN file_managed AS f
		ON s.field_store_images_fid = f.fid
		ORDER BY s.delta
	";

	// Use drupal's db_query function 
  $about_query = db_query( $about_query_string );
  $about_text = $about_query->fetchAll();

  // Use drupal's db_query function 
  $store_query = db_query( $store_query_string );
  $store_images = $store_query->fetchAll();

  // About page text
  $about_text_final = $about_text[0]->field_about_text_value;

  //dsm($store_images);

  // Loop through store images
  foreach ( $store_images as $key => $image ) {
  	
  	// Init
  	$store_uri = $image->uri;

  	$store_img_vars = array(
	    'style_name' => 'store',
	    'path' => $store_uri,
	    'width' => '',
	    'height' => '',
		);
		
		// Theme the image with the style
		$store_img_styled = theme_image_style($store_img_vars);

		$slider_img = $store_img_styled;

		$slider_imgs .= "
			<li>
				$slider_img
			</li>
		";

  }


  $about = "
  	<section id=\"about\" class=\"text-center large-section gap\">
  		<article>
  			<h1>About</h1>
  			<div class=\"max-text\">
  				$about_text_final
  			</div>
  			<div class=\"flexslider\">
  				<ul class=\"slides\">
  					$slider_imgs
  				</ul>
  			</div>
  		</article>
  	</section>
  ";

  $scroller = "
  	<section class=\"img-full\" data-stellar-background-ratio=\"0.5\">
  	</section>
  ";

  // <img src=\"/sites/all/themes/clim/images/wood.jpg\" />
  // $scroller = "
  // 	<div id=\"main-scroller\"></div>
  // ";

  $brands = "
  	<section id=\"brands\" class=\"text-center large-section gap\">
  		<article>
  			<h1>Brands</h1>
	  			$brand
  		</article>
  	</section>
  ";

  $footer = "
  	<footer id=\"footer\" class=\"text-center\">
		  	<h1>Visit</h1>
		  	 <div class=\"hours third\">
		    	<b>Hours</b> </br>
		    	TUE- SAT </br>
		    	8 - 6 </br>
		    </div>
		    <div id=\"address\" class=\"third\">
		      4405 West 43rd Ave </br>
		      Denver, Colorado 80212
		      <div id=\"phone\">
			      603 . 315 . 3187
			    </div>
		    </div>
		    <div id=\"social\" class=\"third\">
		    	<div class=\"social-icon\">
		    		<a href=\"mailto:eli@berkeleysupply.com\" target=\"_blank\">Email
		    		</a>
		    	</div>
		    	<div class=\"social-icon\">
		      	<a href=\"//www.facebook.com/BerkeleySupplyCO?fref=ts\" target=\"_blank\">Facebook</a>
		     	</div>
		     	<div class=\"social-icon\">
		      	<a href=\"//twitter.com/BerkeleySupply/statuses/273145572674899968\" target=\"_blank\">Twitter</a>
		      </div>
		      <div class=\"social-icon\">
			      <a href=\"//instagram.com/berkeleysupply\" target=\"_blank\">Instagram</a>
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