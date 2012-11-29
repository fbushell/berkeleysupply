<div class="frame">
<header id="header">
	<div class="container">
    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
    </a>
	</div>
</header>
</div>

<div class="wrapper" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print $messages; ?>
    <?php print render($page['content']) ?>
</div>
<div class="stripe-top"></div>
<div class="stripe-right"></div>
<div class="stripe-bottom"></div>
<div class="stripe-left"></div>

<footer id="footer">
  <div class="container">
  </div>
</footer> 